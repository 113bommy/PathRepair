def delete(s,pos):
        return str(s[:pos]+s[(pos+1):])
n,m=[int(i) for i in input().split()]
a=str(input())
if n==m:
        print(a)
else:
        m=m//2
        t=a.count('()')
        z=a.count('(')
        if m<=t:
                g='()'*m
                print(g)
        elif (z-t)>=m:
                #print(z,t,m)
                g='('*m + ')'*m
                print(g)
        else:
                while(n!=2*m):
                        x=a.find('(')
                        y=a.find(')')
                        #print(x,y)
                        a=delete(a,x)
                        a=delete(a,y-1)
                        #print(a)
                        n=n-2
                print(a)
                
                
