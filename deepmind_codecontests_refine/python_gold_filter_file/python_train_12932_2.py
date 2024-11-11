def solve(s):
    kb = ""
    st = set()
    al = set("qwertyuiopasdfghjklzxcvbnm")
    p = -1
    l = 0
    for i in s:
        if(i not in st):
            if(p == l - 1):
                st.add(i)
                kb += i
                p += 1
                l += 1
            elif(p == 0):
                st.add(i)
                kb = i + kb
                l += 1
            else:
                return "NO"
        else:
            if(kb[p] == i):
                continue
            if(p > 0):
                if(kb[p - 1] == i):
                    p -= 1
                    continue
            if(p < l - 1):
                if(kb[p + 1] == i):
                    p += 1
                    continue
            return "NO"
    for i in al:
        if(i not in kb):
            kb += i
    return "YES\n" + kb
def main():
    t = int(input())
    for i in range(t):
        print(solve(input()))
main()
