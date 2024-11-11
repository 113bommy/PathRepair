def play(a, b):
    time = 0
    if a < 2 and b < 2:
        return 0

    while a > 0 and b > 0:
        if a > b:
            b += 1
            a -= 2
        else:
            b -= 2
            a += 1
        a = min(a, 100)
        b = min(b, 100)
        time += 1
 #       print("{time}: {a} {b}".format(**locals()))
    return time


def test_one(a, b, right_ans):
    ans = play(a, b)
    if ans == right_ans:
        print("[OK]")
    else:
        print("[Fail] Expected {right_ans} but got {ans} on '{a} {b}'".format(**locals()))

def test():
    test_one(3, 5, 6)
    test_one(4, 4, 5)
    test_one(1, 1, 0)
    test_one(2, 2, 1)
    test_one(3, 3, 3)
    test_one(100, 100, 197)

if __name__ == "__main__":
    ab = list(map(int, input().split()))
    a = ab[0]
    b = ab[1]
    print(play(a, b))
#   test()
