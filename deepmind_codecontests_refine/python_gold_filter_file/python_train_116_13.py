n = int(input())
s = input()
tmp = "a"
ans = -1
for index,i in enumerate(s):
    if i>=tmp:
        tmp = i
    else:
        ans = index
        break
if ans==-1:
    print("NO")
else:
    print("YES")
    print("{} {}".format(ans,ans+1))