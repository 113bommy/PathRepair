from itertools import permutations

def str_base(number,base):
    if number < 0:
        return '-' + str_base(-number, base)
    (d, m) = divmod(number, base)
    if d > 0:
        return str_base(d, base) + str(m)
    return str(m)

n, m = map(int, input().split())

max_h = str_base(n-1, 7)
max_m = str_base(m-1, 7)
len_h = len(max_h)
len_m = len(max_m)

result = 0
for p in permutations(list(range(7)) , len_h + len_m):
    if str(''.join(map(str, p[:len_h]))) <= max_h and str(''.join(map(str, p[len_h:]))) <= max_m:
        result += 1
        
print(result)