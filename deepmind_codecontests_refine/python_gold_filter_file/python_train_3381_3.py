a,b,s=map(int,input().split())
#print(a,b,s)
if(s>=(abs(a)+abs(b)) and (s-(abs(a)+abs(b)))%2==0):
    print("YES")
else:
    print("NO")