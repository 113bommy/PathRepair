import sys

def main():
    for ln in sys.stdin:
        s=ln.strip()
        for x in solve(s):
            print(x)

def solve(s):
    #print()
    #print(s)

    ans=[]
    n=len(s)
    r=l=h=0
    for i in range(n):
        if s[i]=='(':
            r+=1
        elif s[i]==')':
            l+=1
        else:
            h+=1
    if r<=l:
        return [-1]
    b=0
    for i in range(n-1,-1,-1):
        if s[i]==')':
            r-=1
            l-=1
            b+=1
        elif s[i]=='#':
            if r==0:
                return [-1]
            r-=1
            h-=1
            x=r-l-h
            if r-x>=0:
                r-=x
            else:
                x=0
            ans.append(1+x)
            b+=1+x
        else:
            b-=1
            if b<0:
                return [-1]

    ans=ans[::-1]
    return ans

#print(solve('#'))
#print(solve('(#)'))
#print(solve('((#)'))
#print(solve('(((#)((#)'))
#print(solve('()((#((#(#()'))
#print(solve('((((#((#())'))
#print(solve('(((((#'))
#print(solve('##((((((()'))

main()
