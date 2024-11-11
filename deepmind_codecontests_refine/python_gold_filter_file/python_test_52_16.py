def L():
    return list(map(int,input().split()))
def I():
    return int(input())

def solve():
    n,x = map(int,input().split())
    bini = bin(x)
    cout = 0
    ans = 1
    # print(bini)
    for x in bini[2:][::-1]:
        if x == "1":
            ans += n**cout
            ans = ans % 1000000007
        cout += 1
    print(ans-1)



for _ in range(int(input())):
    solve()