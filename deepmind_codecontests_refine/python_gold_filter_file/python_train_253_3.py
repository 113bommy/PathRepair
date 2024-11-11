import sys

def main():
    for ln in sys.stdin:
        s=ln.strip()
        for x in solve(s):
            print(x)

def solve(s):
    ans=[]
    b=0
    for c in reversed(s):
        if c==')':
            b+=1
        elif c=='(':
            b-=1
            if b<0:
                if not ans:
                    return [-1]
                else:
                    ans[-1]+=1
                    b=0
        else:
            b+=1
            ans.append(1)
    if b!=0:
        return [-1]
    return ans[::-1]

#print(solve('#'))
#print(solve('(#)'))
#print(solve('((#)'))
#print(solve('(((#)((#)'))
#print(solve('()((#((#(#()'))
#print(solve('((((#((#())'))
#print(solve('(((((#'))
#print(solve('##((((((()'))
#print(solve('((#)('))

main()
