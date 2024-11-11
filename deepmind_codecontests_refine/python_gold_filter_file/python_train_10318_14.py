#   ==========     //\\       //||     ||====//||
#       ||        //  \\        ||     ||   // ||
#       ||       //====\\       ||     ||  //  ||
#       ||      //      \\      ||     || //   ||
#   ========== //        \\  ========  ||//====|| 
#  code

def solve():
    from collections import Counter as C
    n = int(input())
    s = list(map(int, input().split()))

    c = C(s)
    a = s[:]
    s = list(set(s))

    once = []
    fl = 0
    for i in s:
        if c[i] == 1:
            once.append(i)
        if c[i] > 2:
            fl = i
    
    if len(once) % 2 == 0:
        d = {}
        for i in once[:len(once) // 2]:
            d[i] = 'A'
        for i in once[len(once) // 2:]:
            d[i] = 'B'
        
        st = ""
        for i in a:
            st += d.get(i, 'A')
        
        print('YES')
        print(st)
    else:
        if fl == 0:
            print('NO')
        else:
            d = {}
            for i in once[:len(once) // 2]:
                d[i] = 'A'
            for i in once[len(once) // 2:]:
                d[i] = 'B'

            st = ""
            for i in a:
                if fl == i:
                    st += 'A'
                    fl = 0
                else:
                    st += d.get(i, 'B')
            
            print('YES')
            print(st)


def main():
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()