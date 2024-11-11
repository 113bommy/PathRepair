string = input().lower () 
vowels = ["a","e","i","o","u","y"]
arr= []
for item in string:
   if item not in vowels:
      arr.append(item) 
A = ".".join(arr) 
print ("."+A) 