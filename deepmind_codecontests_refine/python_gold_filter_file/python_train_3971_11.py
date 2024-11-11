def main():
    a = input()
    b = input()
    l = ['a', 'e', 'i', 'o', 'u']
    if (len(a) != len(b)):
        print("No")
        return
    for i in range(min(len(a), len(b))):
        if (a[i] in l and b[i] not in l) or (a[i] not in l and b[i] in l):
            print("No")
            return
    print("Yes")
    return


main()
