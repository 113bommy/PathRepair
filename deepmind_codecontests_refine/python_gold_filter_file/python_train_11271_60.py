#   ==========     //\\       //||     ||====//||
#       ||        //  \\        ||     ||   // ||
#       ||       //====\\       ||     ||  //  ||
#       ||      //      \\      ||     || //   ||
#   ========== //        \\  ========  ||//====|| 
#  code

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        a = ''
        for i in range(0, 2 * n - 1, 2):
            a += s[i]
        print(a)
    return

if __name__ == "__main__":
    main()