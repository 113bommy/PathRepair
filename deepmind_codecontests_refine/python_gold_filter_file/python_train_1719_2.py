s = str(input())
def solve(s,k):
    stack = []
    n = len(s)
    ans = [0]
    prev = 0
    for i in range(n):
        if s[i]==k:
            if stack:
                val = i+1-stack.pop()
                # ans.append(val+prev)
                # prev +=val
                if not stack:
                    prev += val
                    ans.append(prev)
                else:
                    ans.append(val)
            else:
                prev = 0
        else:
            stack.append(i)
        # print(stack,ans[-2:],prev,"INDEX",i)
    Max = max(ans)
    return [Max,ans.count(Max)]
a,b = solve(s,")")
c,d = solve(s[::-1],"(")
if  a>c:
    print(a,b)
elif  a==c:
    print(a,max(b,d))
else:
    print(c,d)