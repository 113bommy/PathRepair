import math
for _ in range(int(input())):
    s=set()
    s.add(0)
    n=int(input())
    for i in range(1,math.ceil(math.sqrt(n))+1):
        s.add(n//i)
        s.add(n//(n//i))
    print(len(s))
    print(*sorted(s))