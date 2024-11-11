n = int(input())
s = input()

dp_a = 0
dp_ab = 0
dp_abc = 0
hatena = 1

mod = 10**9 + 7

if s[0]=="a" or s[0]=="?":
    dp_a = 1
if s[0]=="?":
    hatena = 3

for i in range(1,n):
    if s[i]=="a":
        dp_a = (dp_a + hatena) % mod
    elif s[i]=="b":
        dp_ab = (dp_a + dp_ab) % mod
    elif s[i]=="c":
        dp_abc = (dp_ab + dp_abc) % mod
    else:
        dp_abc = (dp_ab + 3 * dp_abc) % mod
        dp_ab = (3 * dp_ab + dp_a) % mod
        dp_a = (3 * dp_a + hatena) % mod
        hatena = (hatena * 3) % mod

print(dp_abc)
