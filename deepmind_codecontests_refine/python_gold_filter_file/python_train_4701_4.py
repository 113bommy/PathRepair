import math
def main():
    n=int(input())
    s=list(input())
    co,cc=0,0
    if(len(s)%2==1):
        print(':(')
    else:
        x,y=s.count('('),s.count(')')
        rx,ry=n//2-x,n//2-y
        for i in range(n):
            # print(co)
            if(co==0 and i!=0):
                cc=1
                break
                
            if(s[i]=='('):
                co+=1
            elif(s[i]==')'):
                co-=1
            else:
                if(co==0 and i==0):
                    s[i]='('
                    co+=1
                    rx-=1
                elif(co==1 and i==n-1):
                    s[i]=')'
                    co-=1
                    ry-=1
                elif(co==1):
                    s[i]='('
                    co+=1
                    rx-=1
                elif(co>1):
                    if(rx>0):
                        s[i]='('
                        co+=1
                        rx-=1
                    else:
                        s[i]=')'
                        co-=1
                        ry-=1
                # print(rx,ry,co,s)
            if(co<0 or rx<0 or ry<0):
                cc=1
                break
        print(':(' if(cc==1 or co!=0) else ''.join(s))
        # print((cc,rx,ry,x,y) if(n==1000) else '',end='')
    
main()