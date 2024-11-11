
if __name__ == '__main__':
    for _ in range(int(input())):
        n,t = map(int,input().split())
        a = list(map(int,input().split()))
        ans = list()
        k = True
        for i in a:
            if i<t/2:
                ans.append(0)
            elif i == t/2:
                if k:
                    ans.append(0)
                    k = False
                else:
                    ans.append(1)
                    k = True
            else:
                ans.append(1)
        print(*ans)