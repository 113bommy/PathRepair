ai = int(input())
ti = 6
if ai/2 == round(ai/2):
    print(4,ai-4)
else:
    while (ai - ti)%2 != 0:
        ti += 3
    print(ti,ai-ti)

