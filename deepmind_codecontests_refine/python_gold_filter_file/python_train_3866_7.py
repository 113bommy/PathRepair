import sys


def main():
    _ = sys.stdin.readline()
    s = sys.stdin.readline().strip()
    prefix = [0] * (len(s) + 1)
    canPrefix = [True] * (len(s) + 1)
    count = 0
    for i, c in enumerate(s):
        count = count+1 if c == '(' else count-1
        isPossible = True if count >= 0 and canPrefix[i] else False
        prefix[i+1] = count
        canPrefix[i+1] = isPossible
    sufix = [0] * (len(s) + 1)
    canSuffix = [True] * (len(s) + 1)
    count = 0
    for i, c in enumerate(reversed(s)):
        count = count + 1 if c == ')' else count - 1
        isPossible = True if count >= 0 and canSuffix[len(s) - i] else False
        sufix[len(s)-1-i] = count
        canSuffix[len(s)-1-i] = isPossible
    ans = 0
    for i, c in enumerate(s):
        if canPrefix[i] == False or canSuffix[i+1] == False:
            continue
        elif c == '(' and prefix[i] - 1 - sufix[i+1] == 0:
            ans += 1
        elif c == ')' and prefix[i] + 1 - sufix[i+1] == 0:
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()
