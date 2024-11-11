def price(target, item, recipe):
    ret = []
    
    if target in recipe:
        ret.append(sum(price(r,item, recipe) for r in recipe[target]))
    if target in item:
        ret.append(item[target])
    if len(ret) == 0:
        return 0

    return min(ret)

import sys
f = sys.stdin

while True:
    n = int(f.readline())
    if n == 0:
        break
    item = [f.readline().split() for _ in range(n)]
    item = {name:int(price) for name, price in item}
    recipe = [f.readline().strip().split() for _ in range(int(f.readline()))]
    recipe = {r[0]:r[2:] for r in recipe}
    print(price(f.readline().strip(), item, recipe))