def main():
    s = input()
    aFront = 1
    ans = []
    for i in range(1, len(s) + 1):
        needAFront = 1
        if i < len(s) and s[i] == 'a':
            needAFront = 0
        if aFront != needAFront:
            ans.append(1)
        else:
            ans.append(0)
        aFront = needAFront
    print(*ans)
    return

if __name__=="__main__":
    main()