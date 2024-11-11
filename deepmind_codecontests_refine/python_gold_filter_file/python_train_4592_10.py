def main():
    n = int(input())
    for _i in range(n):
        squares = input().split()
        squares[0] = int(squares[0])
        squares[1] = int(squares[1])
        prime_diff(squares[0], squares[1])

def prime_diff(sq1, sq2):
    if sq1 - sq2 == 1 and prime(sq1 + sq2):
        print("YES")
    else:
        print("NO")

def prime(num):
    i = 2
    while i * i <= num:
        if num % i == 0:
            return False
        i += 1
    return True

main()