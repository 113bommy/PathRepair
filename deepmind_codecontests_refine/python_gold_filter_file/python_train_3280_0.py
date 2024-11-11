n = int(input())
a = list(map(int, input().split()))
sa = sum(a)
a.sort(reverse = True)
def main(a, sa):
    if len(a) == 1:
        if sa % 2 == 1:
            print(sa)
        else:
            print(0)
        return
    if sa % 2 == 1:
        print(sa)
    else:
        for i in range(len(a)):
            if (sa - min(a)) % 2 == 1:
                print(sa - min(a))
                return
            else:
                a.pop()
        print(0)
main(a, sa)
