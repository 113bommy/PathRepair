n , k = map(int,input().split())
o = 0
for i in range(n):
    s , s1 = map(int,input().split())
    o += s1 -s
    o+=1
if o % k == 0:
    print(0)
elif o % k == o:
    print(k-o)
elif o% k > 0:
    j =o % k
    print(k-j)

