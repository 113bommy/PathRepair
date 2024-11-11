n=int(input())
p={
    "A":10**9,
    "B":10**9,
    "C":10**9,
    "AB":10**9,
    "BC":10**9,
    "AC":10**9,
    "ABC":10**9
}

for i in range(n):
    x,y=input().split()
    x=int(x)
    y=''.join(sorted(y))
    p[y]=min(p[y],x)

x=min(
        p["A"]+p["B"]+p["C"],
        p["AB"]+p["C"],
        p["AC"]+p["B"],
        p["BC"]+p["A"],
        p["ABC"],
        p["AB"]+p["BC"],
        p["AB"]+p["AC"],
        p["BC"]+p["AC"],
        p["A"]+p["ABC"],
        p["B"]+p["ABC"],
        p["C"]+p["ABC"],
        p["AB"]+p["ABC"],
        p["AC"]+p["ABC"],
        p["BC"]+p["ABC"],
    )
print(x) if x<10**7 else print("-1")
    

    