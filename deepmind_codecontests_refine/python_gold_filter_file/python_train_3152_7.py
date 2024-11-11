h = int(input())
l = []
for i in range(h):
   a,b,x,y,n = list(map(int, input().split()))
   ans = 10**18
   for i in range(2):
       da = min(n, a-x)
       db = min(n - da, b - y)
       ans = min(ans, (a-da)*(b-db))
       a,b = b,a
       x,y = y,x
   l.append(ans)
for i in l:
    print(i)