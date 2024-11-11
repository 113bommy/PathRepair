def main():
    n = int(input())
    for i in range(n):
        solve()
 
def solve():
    n = int(input())
    arr = list(map(int, input().split()))
 
    if len(set(arr)) == 1:
        print(n)
    else:
        print(1)
 
main()