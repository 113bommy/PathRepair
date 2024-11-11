n,m = map(int, input().split())
 
ma = m//n
 
flag=0
 
while(flag==0):
    if m%ma==0:
        print(ma)
        flag = 1
    ma -=1