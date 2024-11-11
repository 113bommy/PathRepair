K = int(input())
A, B = map(int, input().split())
if B - B % K >= A:
    print("OK")
else:
    print("NG")