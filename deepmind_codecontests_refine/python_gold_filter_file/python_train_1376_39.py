n = int(input())
for i in range(n):
    s = input()
    if s[-1] == "u":
        print("JAPANESE")
    elif s[-1] == "o":
        print("FILIPINO")
    else:
        print("KOREAN")