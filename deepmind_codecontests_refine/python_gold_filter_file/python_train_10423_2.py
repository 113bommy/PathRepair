import sys

def mp():
    return list(map(int, input().split()))

def main():
    n = int(input())
    a = input().strip()
    g = a.count('G')
    if g == 0:
        print(0)
        return 
    d = []
    now = 0
    for i in range(n):
        if a[i] == 'G':
            now += 1
        else:
            d.append(now)
            now = 0
    if a[n - 1] == 'G':
        d.append(now)
    ans = max(d)
    if ans != g:
        ans += 1
    # print(d)
    for i in range(len(d) - 1):
        if d[i] + d[i + 1] < g:
            ans = max(ans, d[i] + d[i + 1] + 1)
        else:
            ans = max(ans, d[i] + d[i + 1])
        
    print(ans)
            
koala = 0
if koala:
    file = open('input.txt', 'r')
    input = file.readline
else:
    input = sys.stdin.readline

main()

if koala:
    file.close()