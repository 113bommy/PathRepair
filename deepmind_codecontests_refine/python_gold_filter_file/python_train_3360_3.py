def solve(ratings, n, r):
    if ratings.count(r) == n:
        print(0)
    elif ratings.count(r) > 0:
        print(1)
    elif sum(ratings) == r*n:
        print(1)
    else:
        print(2)

def main():
    t = int(input())
    for i in range(t):
        n, r = list(map(int, input().split()))
        solve(list(map(int, input().split())), n , r)

main()