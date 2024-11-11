import sys, os.path #=========================================================================
if(os.path.exists('in.txt')):sys.stdin = open("in.txt","r");sys.stdout = open("out.txt","w")#=
#=============================================================================================
n, x = map(int, input().split())
s = input()
i = 0
ans = 0
no_ans = False
while(i < n):
    p = i
    ans += 1
    i += x
    if(i >= n-1):break
    if(s[i] != "1"):
        while(s[i] != "1"):
            i -= 1
            if(i <= p):
                no_ans = 1
                break
    if(no_ans):break
if(no_ans):print(-1)
else: print(ans)