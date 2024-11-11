n = int(input())
l = list(map(int,input().split()))
s = {1,2,3,4,5,6}
for i in l:
    if i <= 14:
        print("NO")
        continue


    if i%14 in s:
        print("YES")

    else:
        print("NO")
