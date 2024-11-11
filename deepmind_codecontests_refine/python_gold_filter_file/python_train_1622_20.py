



if __name__ == "__main__":
    N = int(input())
    if N>0:
        a = list(map(int, input().strip().split()))
    else:
        print("NO")
    if (all([x == 0 for x in a])):
        print("NO")
    elif sum(a) != 0:
        print("YES")
        print(1)
        print("1 " + str(len(a)))
    else:
        i=1
        while sum(a[:i]) ==0:
            i += 1
        print("YES")
        print(2)
        print("1 " + str(i))
        print(str(i+1) + " " +str(len(a)))







