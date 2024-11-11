a,b,c=map(int,input().split())
if(c>=abs(a)+abs(b) and (c-(abs(a)+abs(b)))%2==0):
    print("Yes")
else:
    print("No")
