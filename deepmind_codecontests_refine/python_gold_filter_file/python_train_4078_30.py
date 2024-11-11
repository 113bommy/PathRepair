import sys
input = sys.stdin.readline

mod = 998244353

w,h=map(int,input().split())

print(4*pow(2,(w-1)+(h-1),mod)%mod)
