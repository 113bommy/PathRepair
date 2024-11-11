#   ==========     //\\       //||     ||====//||
#       ||        //  \\        ||     ||   // ||
#       ||       //====\\       ||     ||  //  ||
#       ||      //      \\      ||     || //   ||
#   ========== //        \\  ========  ||//====|| 
#  code

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    maxans = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
    minans = max(a[0] - b[0] - b[2],a[1] - b[1] - b[0], a[2] - b[1] - b[2], 0)

    print(minans, maxans)
    return

def main():
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()