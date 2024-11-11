for _ in range(int(input())):
    n=int(input())
    s=input().split()
    for i in range(n-3):
        if(s[i][1]!=s[i+1][0]):
            s.insert(i+1,s[i][1]+s[i+1][0])
            break
    else:
        s.append(s[-1][1]+'a')
    print(s[0][0],end='')
    for i in range(n-1):
        print(s[i][1],end='')
    print()