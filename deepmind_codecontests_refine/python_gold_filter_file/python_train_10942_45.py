t=int(input())
for i in range(t):
    s,a,b,c=map(int,input().split())
    print(s//c+((s//c)//a)*b)
