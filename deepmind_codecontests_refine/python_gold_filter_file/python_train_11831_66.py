def lol_kek():
    s=input()
    s1="aeiou13579"
    p=0
    for i in range(len(s)):
        if s[i] in s1:
            p+=1
    print(p)
lol_kek()

