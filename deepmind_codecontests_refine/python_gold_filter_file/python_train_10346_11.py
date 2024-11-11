def binNumber(n,size):
    return bin(n)[2:].zfill(size)

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)

#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#code
n,k = map(int,input().split())
ma = -1e18
for _ in range(n):
    f,t = map(int,input().split())
    su = 0
    if t > k:
        su = f - t + k
    else:
        su = f
    ma = max(ma,su)
print(ma)