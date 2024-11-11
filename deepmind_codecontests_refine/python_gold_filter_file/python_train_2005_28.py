def main():
    for _ in range(int(input())):
        n=int(input())
        a=list(input());b=list(input())
        ans=[]
        for i in range(n-1,-1,-1):
            if a[i]==b[i]:
                continue
            if a[i]!=b[i] and a[0]!=b[i]:
                ans.append(i+1)
            elif a[i]!=b[i] and a[0]==b[i]:
                ans.append(1)
                ans.append(i+1)
                if a[0]=='1':
                    a[0]='0'
                else:
                    a[0]='1'
            if i<n-1:
                a=a[:i+1][::-1]+a[i+1:]
            else:
                a=a[:i+1][::-1]
            for j in range(i+1):
                if a[j]=='0':
                    a[j]='1'
                else:
                    a[j]='0'
        print(len(ans),end=' ')
        print(*ans)
main()