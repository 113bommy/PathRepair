import math
def solve(n,k,s):
    start = s.find("G")
    end = s.find("T")
    while start < n and start <= end:
        if start == end:
            return "YES"
        start += k
        if start >=  n:
            return "NO"
        if s[start] == "#":
            return "NO"
    while start >= 0 and  start >= end:
        if start == end:
            return "YES"
        start -= k
        if start < 0:
            return "NO"
        if s[start] == "#":
            return "NO"
    return "NO"
n,k = map(int,input().split())
# a = int(input())
# b = int(input())
# c = int(input())
# l = list(map(int,input().split()))
s = input()
print(solve(n,k,s))




