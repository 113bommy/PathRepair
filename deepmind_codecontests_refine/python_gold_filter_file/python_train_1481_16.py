'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''

n=int(input())
aa=list(map(int,input().split()))
def help(a,bits):
    if len(a)<=1 or bits<0:
        return 0
    s,u=list(),list()
    for i in a:
        if ((i>>bits)&(1))==0:
            u.append(i)
        else:
            s.append(i)
#    print(s,u)
    if len(u)==0:
        return help(s,bits-1)
    elif len(s)==0:
        return help(u,bits-1)
    return min(help(u,bits-1),help(s,bits-1))+(1<<(bits))
print(help(aa,30))
