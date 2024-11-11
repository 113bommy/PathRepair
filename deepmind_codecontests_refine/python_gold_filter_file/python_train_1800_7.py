t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    count = 1
    for j in range(1,n):
        if s[j]==s[j-1]:
            count+=1
    print(count//2)