import math

def main():
    n = int(input())
    if n <= 2:
        print(1)
    else:

        res = 0.5/math.sin(math.pi/(4*n))
        print(res)


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        main()