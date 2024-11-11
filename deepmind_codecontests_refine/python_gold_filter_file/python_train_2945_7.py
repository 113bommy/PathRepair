pn = int(input())
nn = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157]
for i in range(pn):
    n = int(input())
    if nn.count(n) == 1:
        ans =[1 for i in range(n)]
        for i in range(n):
            print(*ans)
    else:
        ans = [1 for i in range(n)]
        for i in nn:
            if i >n and nn.count(1+i-n) == 0:
                for j in range(n):
                    ans = [1 for i in range(n)]
                    ans[j]=1+i-n
                    print(*ans)
                break



