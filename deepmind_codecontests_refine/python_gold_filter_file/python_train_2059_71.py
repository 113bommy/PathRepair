a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())

if v-w>0 and abs(a-b)/(v-w)<=t:
    print("YES")
else:
    print("NO")