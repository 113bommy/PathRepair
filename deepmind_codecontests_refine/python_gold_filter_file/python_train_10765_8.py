n=(input())
b=int(n)
for i in range(len(str(n))):
   if n[len(n)-1-i]=="0":
    print("O-|-OOOO")
   elif n[len(n) - 1 - i] == "1":
       print("O-|O-OOO")
   elif n[len(n) - 1 - i] == "2":
        print("O-|OO-OO")
   elif n[len(n) - 1 - i] == "3":
        print("O-|OOO-O")
   elif n[len(n) - 1 - i] == "4":
        print("O-|OOOO-")
   elif n[len(n) - 1 - i] == "5":
        print("-O|-OOOO")
   elif n[len(n) - 1 - i] == "6":
        print("-O|O-OOO")
   elif n[len(n) - 1 - i] == "7":
        print("-O|OO-OO")
   elif n[len(n) - 1 - i] == "8":
        print("-O|OOO-O")
   elif n[len(n) - 1 - i] == "9":
       print("-O|OOOO-")

