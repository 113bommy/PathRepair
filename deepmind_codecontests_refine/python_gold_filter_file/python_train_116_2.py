

def main():
    n = int(input())
    s = input()

    done = False
    for i in range(n-1, 0, -1):
        if s[i] < s[i-1]:
            print("YES")
            print(i, i+1)
            done = True
            break

    if not done:
        print("NO")


if __name__ == "__main__":
    main()