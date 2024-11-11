t=int(input())
while(t):
    s=input()
    x=len(s)
    if s[x-2:]=="po":
        print("FILIPINO")
    elif s[x-4:]=="desu" or s[x-4:]=="masu":
        print("JAPANESE")
    else:
        print("KOREAN")
    t=t-1 