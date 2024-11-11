from sys import stdin
from sys import stdout

sprint = stdout.write
sinput = stdin.readline

#[int(x) for x in sinput().split()]
#int(sinput())


def func():
    n,x = [int(x) for x in sinput().split()]
    arr = [int(x) for x in sinput().split()]
    ne = 0
    no = 0
    for i in range(len(arr)):
        arr[i] = arr[i]%2
        if arr[i] == 0:
            ne += 1
        else:
            no += 1
    if x > ne:
        x -= ne if (x-ne)%2 != 0 else max(ne-1,0)
    else:
        x = 1
    if x%2 == 1 and no>=x:
        print('YES')
    else:
        print("NO")


if __name__ == "__main__":
    t = int(sinput())
    while t != 0:
        t -= 1
        func()
