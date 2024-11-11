S = input()
print("AC" if S[0] == "A" and S[2:-1].count("C") ==
      1 and S[1:].replace("C", "", 1).islower() else "WA")
