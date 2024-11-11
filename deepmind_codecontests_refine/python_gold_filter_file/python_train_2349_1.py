a,b = (int(i) for i in input().split())
if b< a:
    print("NO")
    exit(0)
ans = 0
ans_l = [b]
while b > a:
    if b%2 == 0 and b/2 >= a:
        ans+=1
        b//=2
        ans_l+=[b]
    elif b%10 == 1 and b//10 >= a:
        ans+=1
        b//=10
        ans_l+=[b]
    else:
        print("NO")
        exit(0)
print("YES")
print(ans+1)
print(' '.join(list(map(str,ans_l[::-1]))))
