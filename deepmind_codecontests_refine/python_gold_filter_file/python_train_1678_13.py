n = int(input())
for i in range(n):
    l,v,r,d=map(int,input().split())
    print(l//v-d//v+(r-1)//v)