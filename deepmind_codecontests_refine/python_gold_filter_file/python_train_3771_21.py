def main():
    n = int(input())
    s = input()
    fst_lst = [s[0]]
    snd_lst = []
    ans = '1'
    for i in range(1, len(s)):
        if fst_lst[-1]<=s[i]:
            fst_lst.append(s[i])
            ans+='1'
        else:
            snd_lst.append(s[i])
            ans+='0'
    # print (*fst_lst)
    # print (*snd_lst)
    if sorted(snd_lst)==snd_lst:
        print ('YES')
        print (ans)
    else:
        print ('NO')
main()

