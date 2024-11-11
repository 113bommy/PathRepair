n = int(input())
for _ in range(n):
    c,s = map(int,input().split())
    b = s//c
    k = s%c
    sum = k*(b+1)**2
    sum+= (c-k)*((b)**2)
    print(sum)