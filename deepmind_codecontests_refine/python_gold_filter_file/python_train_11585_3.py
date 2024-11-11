#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

# MOD = 998244353
# def pow(base , exp):
#     if exp == -1:
#         return pow(base , MOD - 2)
#     res = 1
#     base %= MOD
#     while exp > 0:
#         if exp % 2:
#             res = (res * base) % MOD
#         exp //= 2
#         base = (base * base) % MOD
    
#     res %= MOD
    #   return res

def main():
    t = int(input())
    for _ in range(t):
        a , b  = map(int , input().split())
        if a == b:
            print(0)
        elif a % 2 == b % 2:
            if a % 2 == 1:
                if a < b:
                    print(2)
                else:
                    print(1)
            else:
                if a < b:
                    print(2)
                else:
                    print(1)
        else:
            if a % 2 == 1:
                if a < b:
                    print(1)
                else:
                    print(2)
            else:
                if a < b:
                    print(1)
                else:
                    print(2)

    return

if __name__ == "__main__":
    main()