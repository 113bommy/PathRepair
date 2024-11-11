import math

def main():
    x = int(input())
    j = 20

    print(39)
    while j:
        k = int(math.log2(x)) + 1
        x = x ^ (2**k - 1)
        x = x + 1
        print(k, end=' ')
        j = j - 1

if __name__ == "__main__":
    main()